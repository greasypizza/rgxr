workspace(name = "greasypizza_rgxr")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_googlesource_code_re2",
    sha256 = "91e2d818e0b3131d28b81c0eefa7639f7a6e1568abfdc06b1e9b990b2b603eb1",
    strip_prefix = "re2-d1394506654e0a19a92f3d8921e26f7c3f4de969",
    urls = ["https://github.com/google/re2/archive/d1394506654e0a19a92f3d8921e26f7c3f4de969.zip"],  # 2019-12-14T03:01:08Z
)

http_archive(
    name = "com_google_absl_oss_federation",
    sha256 = "e7ae31ab6109867106e524d2df3c6691c6bd865d8e93f3706faa2d8d639ad6b8",
    strip_prefix = "federation-head-7199628b7c34629a53b5b1bd69ce88967f2ce4e6",
    urls = ["https://github.com/abseil/federation-head/archive/7199628b7c34629a53b5b1bd69ce88967f2ce4e6.zip"],  # 2019-12-20T08:50:59Z
)

load("@com_google_absl_oss_federation//:federation_deps.bzl", "federation_deps")

federation_deps()
