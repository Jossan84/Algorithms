
function [minIndex] = findMin(array) 
  
  minor = array(1);
  minIndex = 1;
  
  for i = 1: length(array)
    if array(i) < minor
      minor = array(i);
      minIndex = i;
    endif
  end
  
endfunction
