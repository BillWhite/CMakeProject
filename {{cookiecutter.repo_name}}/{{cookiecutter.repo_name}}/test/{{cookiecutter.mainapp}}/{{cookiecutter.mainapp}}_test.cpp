#include <string>
#include <gtest/gtest.h>
#include "{{ cookiecutter.mainlib }}/{{ cookiecutter.mainlib }}.hpp"
/************************************************************************
 * Copyright {{ current_year }} by the copyright holders
 * named in COPYING.md.
 *
 * Licensed under: {{ cookiecutter.license }}
 * See https://spdx.dev or LICENSE.md in this
 * project for the license text.
 ************************************************************************/


TEST({{cookiecutter.mainapp}}_Test, BasicAssertions) {
    std::string answer = {{ cookiecutter.mainlib }}(100);
    EXPECT_STREQ(answer.c_str(), "{{cookiecutter.mainlib}}: 100");
}
