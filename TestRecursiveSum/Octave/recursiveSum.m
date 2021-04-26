
function result = recursiveSum(array)
  if length(array) == 0
    result = 0;
  else
    result = array(1) + recursiveSum(array(2:end));
end
