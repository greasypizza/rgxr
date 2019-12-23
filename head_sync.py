#!/usr/bin/env python
'''
This script uses GitHub API to construct http_archive element to be inserted
into a federation client projects bazel WORKSPACE
'''
import hashlib
import json
import urllib3

HTTP_ARCHIVE_TEMPLATE = """http_archive(
    name = "{}",
    urls = ["{}"],  # {}
    strip_prefix = "{}-{}",
    sha256 = "{}",
)"""

_HEADERS = {'User-Agent': 'Workspace Updater'}

http = urllib3.PoolManager()


class ExternalDependency(object):
    def workspace_rule(self):
        raise NotImplementedError('must implement workspace_rule()')


class GitHubProject(ExternalDependency):
    def __init__(self, name, owner, repo, branch):
        self.name = name
        self.owner = owner
        self.repo = repo
        self.branch = branch

    def workspace_rule(self):
        # https://developer.github.com/v3/repos/commits/
        url = 'https://api.github.com/repos/{}/{}/commits/{}'.format(
                project.owner, project.repo, project.branch)
        request = http.request('GET', url, headers=_HEADERS)
        response = json.loads(request.data.decode('utf-8'))
        commit = response["sha"]
        date = response["commit"]["committer"]["date"]

        url = 'https://github.com/{}/{}/archive/{}.zip'.format(
            project.owner, project.repo, commit)
        request = http.request('GET', url, headers=_HEADERS)
        sha256 = hashlib.sha256(request.data).hexdigest()
        return HTTP_ARCHIVE_TEMPLATE.format(
            project.name, url, date, project.repo, commit, sha256)


PROJECTS = [
    GitHubProject(
        'com_google_absl_oss_federation',
        'abseil', 'federation-head', 'master'),
    GitHubProject('com_googlesource_code_re2', 'google', 're2', 'abseil'),
]

for project in PROJECTS:
    retVal = project.workspace_rule()
    print ("********** INSERT THIS INTO YOUR WORKSPACE: *****************")
    print (retVal)
    print ("*********************************")
