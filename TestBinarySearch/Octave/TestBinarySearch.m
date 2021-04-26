%TestBinarySearch
%14/01/2021

close all;
clear;
clc;

list = 1:240000;
num2Find = 1200;
N = length(list);

% Simple Search
tic;
pos = SimpleSearch(list, num2Find);
SimpleSearchTime = toc
SimpleSearchNumberOfSteps = N

% Binary Search
tic;
pos_  = BinarySearch(list, num2Find);
BinarySearchTime = toc
BinarySearchNumberOfSteps = log2(N)
