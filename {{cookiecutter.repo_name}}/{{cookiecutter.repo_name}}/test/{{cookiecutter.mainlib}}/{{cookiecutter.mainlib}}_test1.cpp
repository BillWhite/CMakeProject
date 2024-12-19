#include <string>
#include "gtest/gtest.h"
#include "{{ cookiecutter.mainlib }}/{{ cookiecutter.mainlib }}.hpp"

TEST({{cookiecutter.mainlib}}_Test, BasicAssertions) {
    std::string answer = {{ cookiecutter.mainlib }}(100);
    EXPECT_STREQ(answer.c_str(), "{{cookiecutter.mainlib}}: 100");
}
