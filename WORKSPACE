
workspace(name = "greasypizza_rgxr")

git_repository(
  name = "com_googlesource_code_re2",
  remote = "https://github.com/google/re2.git",
  commit = "06c79cbc93796b2bda126be78b91b0aa3f5c9237",
)
bind(
  name = "re2",
  actual = "@com_googlesource_code_re2//:re2",
)

git_repository(
  name = "gflags_github",
  remote = "https://github.com/gflags/gflags.git",
  commit = "a69b2544d613b4bee404988710503720c487119a",
)
bind(
  name = "gflags",
  actual = "@gflags_github//:gflags",
)