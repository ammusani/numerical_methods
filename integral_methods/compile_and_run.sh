#!/bin/bash

gcc trapezoidalTest.c numericalIntegration.h testFunction.h -o tTest -lm
./tTest
gcc simpsonTest.c numericalIntegration.h testFunction.h -o sTest -lm
./sTest
rm tTest sTest
