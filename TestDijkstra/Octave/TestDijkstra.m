% TestDijkstra
% 09/05/2021

close all;
clear;
clc;

if sum(version <'5.1.0')
  pkg load java
end  

% Definition of the graph table

% Node init
% With structures
%graph = struct("init", {struct("a",6), struct("b", 2)}, ...
%               "a", struct("end",1), ...
%               "b", {struct("a",3), struct("end",5)}, ...
%               "end", []);
 
% With JavaObject
graph = javaObject("java.util.Hashtable");
init = javaObject("java.util.Hashtable");
graph.put('init', init);
##init.put('a', 6); 