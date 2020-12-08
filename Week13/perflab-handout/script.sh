#!/bin/bash
SET=$(seq 0 9) #10 reps
for i in $SET
do
	./driver >> ./log
done
