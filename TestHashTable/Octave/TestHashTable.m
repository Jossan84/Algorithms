%TestHashTable.m
%05/04/2021

close all;
clear;
clc;

% OPTION 1
if ~strcmp(version, '5.1.0')
  pkg load java
end  
book = javaObject("java.util.Hashtable");

book.put('apple', 0.67);
book.put('milk', 1.49);
book.put('lemon', 1.49);

disp(book.get('lemon'));

% OPTION 2
keys = {'apple','milk','lemon'};
values = {0.67, 1.49, 1.49};

book1 = struct();
for i=1:numel(keys)
    book1.(keys{i}) = values{i};
end
disp(book1.('lemon'));