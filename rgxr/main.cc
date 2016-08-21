#include <iostream>
#include <random>

#include "gflags/gflags.h"
#include "re2/re2.h"

DEFINE_int32(len, 15, "Length of generated password");
DEFINE_string(expr, ".*", "RE2 expression");

constexpr char kMinPrintable = '!';
constexpr char kMaxPrintable = '~';
constexpr char kUsage[] = "Generate password matching RE2 expressions.";

int main(int argc, char** argv) {
  gflags::SetUsageMessage(kUsage);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  RE2 expr(FLAGS_expr, RE2::Quiet);
  if (!expr.ok()) {
    std::cout << expr.error() << std::endl;
    gflags::ShowUsageWithFlagsRestrict(argv[0], "rgxr");
    return -1;
  }

  if (FLAGS_len < 1) {
    std::cout << "len must be > 0" << std::endl;
    gflags::ShowUsageWithFlagsRestrict(argv[0], "rgxr");
    return -1;
  }
  std::string result(FLAGS_len, kMinPrintable);

  std::random_device rd;
  std::uniform_int_distribution<char> dist(kMinPrintable, kMaxPrintable);

  do {
    for (char& c : result) {
      c = dist(rd);
    }
  } while (!RE2::FullMatch(result, expr));

  std::cout << result << std::endl;
  return 0;
}