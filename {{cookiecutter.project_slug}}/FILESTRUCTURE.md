# File Structure
This is an explanation of the file structure that the cookiecutter
generated for you.

- {{ cookiecutter.project_slug }}/<br/>
    The top directory is not the source directory. It is one above the
    source directory. We put things here, like configuration files, which
    are not really source files. This is a good place to put out-of-tree
    build directories.
   - {{ cookiecutter.project_slug }}/{{ cookiecutter.project_slug }}/<br/>
      This is the source directory.
   - {{ cookiecutter.project_slug }}/pbin/</br>
      This holds useful command for working with projects.
     - {{ cookiecutter.project_slug }}/pbin/configure-{{ cookiecutter.project_slug }}<br/>
        This shell command runs cmake with the proper arguments. Look
        at the comment in this file for more details.
     - {{ cookiecutter.project_slug }}/pbin/{{ cookiecutter.project_slug }}-shell<br/>
        This shell command starts a subshell with pbin put on the path, and
        with some other environment variables set to interesting values.
        Think of it as something like "poetry shell" in python.
     - {{ cookiecutter.project_slug }}/resources/<br/>
        This directory has resources that don't really belong in the
        source directory, but are needed for configuring things.

# Build Targets
Here we use ninja as a build tool, but make works as well.

- ninja<br/>
   Make the project and tests.
- ninja test<br/>
   Make the project and then run ctest.
- ninja doxygen<br/>
   Make the doxygen documentation.  Don't make the project itself.
- ninja sphinx_html<br/>
   Make the sphinx documentation. Don't make the project itself.
