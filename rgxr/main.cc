#include <iostream>
#include <random>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "re2/re2.h"

ABSL_FLAG(int, len, 15, "Length of generated password");
ABSL_FLAG(std::string, expr, ".*", "RE2 expression");

constexpr char kMinPrintable = '!';
constexpr char kMaxPrintable = '~';
constexpr char kUsage[] = "Generate password matching RE2 expressions.";

int main(int argc, char **argv) {
  absl::SetProgramUsageMessage(kUsage);
  absl::ParseCommandLine(argc, argv);

  const std::string expr_str = absl::GetFlag(FLAGS_expr);
  const int len = absl::GetFlag(FLAGS_len);

  RE2 expr(expr_str, RE2::Quiet);
  if (!expr.ok()) {
    std::cout << expr.error() << std::endl;
    // gflags::ShowUsageWithFlagsRestrict(argv[0], "rgxr");
    return -1;
  }

  if (len < 1) {
    std::cout << "len must be > 0" << std::endl;
    // gflags::ShowUsageWithFlagsRestrict(argv[0], "rgxr");
    return -1;
  }
  std::string result(len, kMinPrintable);

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
