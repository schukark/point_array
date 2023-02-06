project(Tree)

as_library()

project_link_projects(Node)
include_projects_directories(Node)

with_test(Tree gtest_main)