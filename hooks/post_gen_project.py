#
# Note: This script was stolen shamelessly from
#           https://github.com/ssciwr/cookiecutter-cpp-project
#       That cookiecutter project is much more sophisticated than
#       this one. You really should look into it.
#
# This script executes after the project is generated from your cookiecutter.
# Details about hooks can be found in the cookiecutter documentation:
# https://cookiecutter.readthedocs.io/en/latest/advanced/hooks.html
#
# An example of a post-hook would be to remove parts of the project
# directory tree based on some configuration values.

import os
import subprocess
import sys
from cookiecutter.utils import rmtree


class GitRepository(object):
    """ A context for the setup of a Git repository """
    def __init__(self):
        self.remotes = {}

    def __enter__(self):
        # Initialize the git repository
        subprocess.check_call("git init".split())
        subprocess.check_call("git checkout -b main".split())
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        # Finalize by making an initial git commit
        # Maybe add the intial files and commit them.
        if "{{ cookiecutter.add_git_initial_files }}" == "Yes" :
            subprocess.check_call("git add *".split())
            if "{{ cookiecutter.commit_git_repository }}" == "Yes" :
                subprocess.check_call(["git", "commit", "-m", "Initial Commit"])


    def add_remote(self, name, url):
        if self.remotes.get(name, url) != url:
            sys.stderr.write("Trying to add a remote repository twice with differing URL!")
            sys.exit(1)

        if name not in self.remotes:
            self.remotes[name] = url
            subprocess.check_call(["git", "remote", "add", name, url])

    def add_submodule(self, url, location, branch=None, tag=None):
        command = ["git", "submodule", "add"]
        if branch is not None:
            command = command + ["-b", branch]
        command = command + [url, location]
        subprocess.check_call(command)
        if tag is not None:
            subprocess.check_call(["git", "checkout", tag], cwd=os.path.join(os.getcwd(), *os.path.split(location)))


# Optionally remove files whose existence is tied to disabled features
def conditional_remove(condition, path):
    if condition:
        if os.path.isfile(path):
            os.remove(path)
        else:
            rmtree(path)

conditional_remove("{{ cookiecutter.readthedocs }}" == "No", "{{cookiecutter.repo_name}}/doc/.readthedocs.yml")
conditional_remove("{{ cookiecutter.readthedocs }}" == "No", "{{cookiecutter.repo_name}}/doc/conf.py")
conditional_remove("{{ cookiecutter.readthedocs }}" == "No", "{{cookiecutter.repo_name}}/doc/index.rst")
conditional_remove("{{ cookiecutter.readthedocs }}" == "No", "{{cookiecutter.repo_name}}/doc/requirements-rtd.txt")
conditional_remove("{{ cookiecutter.doxygen }}" == "No" and "{{ cookiecutter.readthedocs }}" == "No", "{{cookiecutter.repo_name}}/doc")
conditional_remove(os.stat("{{cookiecutter.repo_name}}/TODO.md").st_size == 0, "{{cookiecutter.repo_name}}/TODO.md")


# Set up a Git repository with submodules
if "{{ cookiecutter.init_git_repository }}" == "Yes" :
    ## This is kind of magic. The with statement, or rather constructing
    ## The GitRepository object, initializes the git repository.
    with GitRepository() as repo:
        if "{{cookiecutter.remote_url}}" != 'None':
               repo.add_remote("origin", "{{ cookiecutter.remote_url }}")

# Print a message about success
print("The project {{ cookiecutter.repo_name }} was successfully generated!")
print("The file FILESTRUCTURE.md describes the purpose and content of all the generated files.")
if os.path.exists("TODO.md"):
    print("A TODO list for you to finalize the generation process was also generated, see TODO.md.")
