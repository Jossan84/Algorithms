% SimpleSearch.m
% 14/01/2021

function pos = SimpleSearch(list, num)

  for i = 1 : length(list)
    if num == list(i)
      pos = list(i);
      break;
    end  
  end
  
end