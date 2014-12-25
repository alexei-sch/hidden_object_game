#pragma once

namespace Tests
{

typedef const QMetaObject* QMetaObjectPtr;
typedef QMetaObjectPtr* QMetaObjectPtrArray;

struct TestObjects
{
	QMetaObjectPtrArray array;
	int count;
};

#define TEST_FUNCTION_NAME queryTestObjects
#define TO_STR(arg) #arg
#define TEST_FUNCTION_NAME_STR TO_STR(queryTestObjects)

//! declare tests suite
#define TESTS(...) \
extern "C" \
{ \
_declspec(dllexport) TestObjects TEST_FUNCTION_NAME() \
{ \
	static QMetaObjectPtr array[] = {__VA_ARGS__}; \
	static TestObjects testObjects = {array, _countof(array)}; \
	return testObjects; \
} \
}

//! declare single test
#define TEST(classname) &classname::staticMetaObject

}