%quickSort.m
%24/03/2021
function sortedArray = quickSort( array )
  if length( array ) < 2
    sortedArray = array;  
  else
    pivot = array(1);
    minor = array(array < pivot);   
    mayor = array(array > pivot);
    sortedArray = [quickSort(minor), pivot, quickSort(mayor)];
  end
end
