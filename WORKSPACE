workspace(name = "greasypizza_rgxr")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_googlesource_code_re2",
    sha256 = "b64d2068fc8c24977500eed0142471a3f2a6d2c7db77110bb3a01419696aab23",
    strip_prefix = "re2-0d8d43fbabc432c1e61219059ef28743f231b6f1",
    urls = ["https://github.com/google/re2/archive/0d8d43fbabc432c1e61219059ef28743f231b6f1.zip"],  # 2021-04-11T14:34:07Z
)

http_archive(
    name = "com_google_absl_oss_federation",
    sha256 = "a24fb8d4cdc507e75a35a49cd16f375286f64a94a2f4c776dbea5e1507f22bff",
    strip_prefix = "federation-head-84209aa4454a0ee49a41eb82b2b959e358d0fa64",
    urls = ["https://github.com/abseil/federation-head/archive/84209aa4454a0ee49a41eb82b2b959e358d0fa64.zip"],  # 2021-04-03T08:18:10Z
)

load("@com_google_absl_oss_federation//:federation_deps.bzl", "federation_deps")

federation_deps()
