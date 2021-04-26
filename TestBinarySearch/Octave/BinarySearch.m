% BinarySearch.m
% 14/01/2021

function pos = BinarySearch(list, num)

  max = length(list);
  min = 1;

  while min <= max
    
    mid = round((list(min) + list(max)) / 2);
    est = list(mid);
    
    if est == num
      pos = est;
    end
    
    if est > num
      max = mid - 1;
    else
      min = mid + 1;
    end
    
  end  
  
  
end
