#!/usr/bin/env python
'''
This script uses GitHub API to construct http_archive element to be inserted
into a federation client projects bazel WORKSPACE
'''
import hashlib
import json
import urllib3

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
        url = f'https://api.github.com/repos/{self.owner}/{self.repo}/commits/{self.branch}'
        request = http.request('GET', url, headers=_HEADERS)
        response = json.loads(request.data.decode('utf-8'))
        commit = response["sha"]
        date = response["commit"]["committer"]["date"]

        url = f'https://github.com/{self.owner}/{self.repo}/archive/{commit}.zip'
        request = http.request('GET', url, headers=_HEADERS)
        sha256 = hashlib.sha256(request.data).hexdigest()
        return f"""
http_archive(
    name = "{self.name}",
    sha256 = "{sha256}",
    strip_prefix = "{self.repo}-{commit}",
    urls = ["{url}"],  # {date}
)"""


PROJECTS = [
    GitHubProject(
        name='com_google_absl_oss_federation',
        owner='abseil',
        repo='federation-head',
        branch='master',
    ),
    GitHubProject(
        name='com_googlesource_code_re2',
        owner='google',
        repo='re2',
        branch='abseil',
    ),
]

print("********** INSERT THIS INTO YOUR WORKSPACE: *****************")
for project in PROJECTS:
    print(project.workspace_rule())
print("*********************************")
