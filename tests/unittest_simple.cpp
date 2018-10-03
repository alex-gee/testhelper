#include <testhelper/foo.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class FooMock : public Foo
{
public:
  MOCK_METHOD0(sayHello, bool());
};
typedef std::unique_ptr<FooMock> FooMockUniquePtr;

class TestObject
{
public:
  TestObject(FooUniquePtr foo):
    foo_(std::move(foo)){}

  void useFoo()
  {
    foo_->sayHello();
  }
private:
  FooUniquePtr foo_;
};

// Declare another test
TEST(TestSuite, testCase2)
{

  FooMockUniquePtr foo(new FooMock());
  FooMock* foo_raw_ptr = foo.get();

  // Define that a call should happen at (*)
  EXPECT_CALL(*foo_raw_ptr, sayHello())
    .Times(1);

  // Inject foo
  TestObject testObject(std::move(foo));

  // Let the testobject call foo 
  testObject.useFoo(); //(*)

  // This will result in segmentation fault since foo was transfered!
  // foo.get()->sayHello();

  // This still works, but test would fail since we EXPECT_CALL.Times(1)
  // foo_raw_ptr->sayHello();
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}