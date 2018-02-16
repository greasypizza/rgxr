workspace(name = "greasypizza_rgxr")

git_repository(
    name = "com_googlesource_code_re2",
    commit = "3d3d6faede5166fad62befda919edc3759294acc",
    remote = "https://github.com/google/re2.git",
)

bind(
    name = "re2",
    actual = "@com_googlesource_code_re2//:re2",
)

git_repository(
    name = "gflags_github",
    commit = "a69b2544d613b4bee404988710503720c487119a",
    remote = "https://github.com/gflags/gflags.git",
)

bind(
    name = "gflags",
    actual = "@gflags_github//:gflags",
)

