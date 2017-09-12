cmake_minimum_required(VERSION 3.8)
project(expressions)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp expression.cpp expression.h numberExpression.cpp numberExpression.h variableExpression.cpp variableExpression.h addExpression.cpp addExpression.h subExpression.cpp subExpression.h mulExpression.cpp mulExpression.h divExpression.cpp divExpression.h powExpression.cpp powExpression.h)
add_executable(expressions ${SOURCE_FILES})