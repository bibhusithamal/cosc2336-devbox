# source files in this project (for beautification)
VERSION=0.3
BASE_DIR := ../assg-base-$(VERSION)
PROJECT_NAME=assg

assg_src  = Queue.cpp \
	    AQueue.cpp \
	    APriorityQueue.cpp \
	    LQueue.cpp \
	    LPriorityQueue.cpp \
	    QueueException.cpp \
	    Job.cpp

test_src  = test-AQueue.cpp \
	    test-LQueue.cpp \
	    test-APriorityQueue.cpp \
	    test-LPriorityQueue.cpp \
	    ${assg_src}

debug_src = main.cpp \
	    ${assg_src}

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include $(BASE_DIR)/include/Makefile.inc

