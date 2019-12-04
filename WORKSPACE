workspace(name = "greasypizza_rgxr")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "com_googlesource_code_re2",
    commit = "79ef3b2d31f06493f687ef9e947d9632bad54b9b",
    remote = "https://github.com/google/re2.git",
)

http_archive(
    name = "com_google_absl",
    sha256 = "c6a20dfedf17f3f64b090388bdb12ebdfe63e9e1e2249b813bce2e2228a77e27",
    strip_prefix = "abseil-cpp-a4b757b5d42694306a9de853cee0a5fba9c7bbe9",
    urls = [
        "https://github.com/abseil/abseil-cpp/archive/a4b757b5d42694306a9de853cee0a5fba9c7bbe9.zip",
    ],
)
