#!/bin/bash

gcc dTrapezTest.c numericalIntegration.h testFunction.h -o tTest -lm
./tTest
gcc dSimpsonTest.c numericalIntegration.h testFunction.h -o sTest -lm
./sTest
rm tTest sTest
