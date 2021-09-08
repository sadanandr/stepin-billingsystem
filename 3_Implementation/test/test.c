#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "fun.h"
#include "unity.h"
#include "struct.h"

void test_delete(void);
void test_search(void);
void test_add(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_delete);
  RUN_TEST(test_search);
  RUN_TEST(test_add);

  /* Close the Unity Test Framework */
  return UNITY_END();
}


void test_delete(void)
{
    char meternumber[20]="KHY123456";
    TEST_ASSERT_EQUAL("KHY123456", meternumber);
   
}

void test_search(void)
{
    char meternumber[20]="KHY123456";
    TEST_ASSERT_EQUAL("KHY123456", meternumber);
   
}

void test_add(void)
{
    char meternumber[20]="KHY123456";

    char name[20]="SOOGURESH";

    char billamount [20]="1000";

 TEST_ASSERT_EQUAL("KHY123456",meternumber);
 TEST_ASSERT_EQUAL("SOOGURESH", name);
 TEST_ASSERT_EQUAL("1000", billamount);
   
}

