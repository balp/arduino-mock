/**
 * Arduino Spark mock
 */
#ifndef SPARK_H
#define SPARK_H

#include <stdint.h>
#include <gmock/gmock.h>

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class SparkMock {
  public:
    MOCK_METHOD2(publish, void(const char *, const char *));
};

class Spark_ {
  public:
    static void publish(const char *eventName, const char *data);
};

SparkMock* sparkMockInstance();
void releaseSparkMock();

#endif // SPARK_H
