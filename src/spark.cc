// Copyright 2014 http://switchdevice.com

#include "arduino-mock/spark.h"

static SparkMock* gSparkMock = NULL;
SparkMock* sparkMockInstance() {
    if(!gSparkMock) {
        gSparkMock = new SparkMock();
    }
    return gSparkMock;
}

void releaseSparkMock() {
    if(gSparkMock) {
        delete gSparkMock;
        gSparkMock = NULL;
    }
}

void Spark_::publish(const char *eventName, const char *data) {
  gSparkMock->publish(eventName, data);
}
