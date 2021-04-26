function [sortedArray] = sortBySelection(array)
  
  sortedArray = zeros(1, length(array));
  
  for i = 1: length(array)
    minIndex = findMin(array);  
    sortedArray(i) = array(minIndex);
    array(minIndex) = [];
  end
    
end
