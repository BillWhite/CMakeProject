This TODO list is automatically generated from the cookiecutter-cpp-project template.
The following tasks need to be done to get a fully working project:

{% if cookiecutter.remote_url == 'None' -%}
* Set up a remote repository. You can e.g. create a project in GitHub or GitLab and run
  the following commands in your locally generated project folder: `git remote add origin <Remote-URL>`
  For a seamless integration, the name of the project should also be `{{ cookiecutter.project_slug }}`.
{%- else %}
* Push to your remote repository for the first time by doing `git push origin main`.
{%- endif %}
* Make sure that the following software is installed on your computer:
  * A C++-{{ cookiecutter.cpp_minimum_standard}}-compliant C++ compiler
  * CMake `>= 3.9`
  * The testing framework [Google Test](https://google.github.io/googletest).
{%- if cookiecutter.readthedocs == "Yes" %}
* Enable the integration of Readthedocs with your Git hoster. In the case of Github, this means
  that you need to login at [Read the Docs](https://readthedocs.org) and click the button
  *Import a Project*.
{%- endif %}
{%- if cookiecutter.doxygen == "Yes" %}
* Make sure that doxygen is installed on your system, e.g. by doing `sudo apt install doxygen`
  on Debian or Ubuntu.
{%- endif %}
