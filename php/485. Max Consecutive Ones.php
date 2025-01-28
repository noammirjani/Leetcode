<?php

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        $max = 0; $curr = 0;
        foreach($nums as $num) {
            if ($num === 0) 
                $curr = 0;
            else 
                $curr++;
            $max = max($curr, $max);
        }
        return $max;
    }
}
$solution = new Solution();
echo $solution->findMaxConsecutiveOnes([1, 1, 0, 1, 1, 1]); // Output: 3
?>