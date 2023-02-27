#!/bin/bash

read -p "num1 = " NUM1
read -p "num2 = " NUM2

sum=`expr $NUM1 + $NUM2`
product=`expr $((NUM1 * NUM2))`

echo "SUM = $sum"
echo "PRODUCT = $product"
