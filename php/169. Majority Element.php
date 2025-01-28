<?php

class Solution {

    /** time ON space O1
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $freq = 0;
        $major_val = 0;

        foreach ($nums as $num) { 
            if ($freq == 0) {
                $major_val = $num;
                $freq = 1; 
            }  
            else if ($num == $major_val)
                $freq++;
            else $freq--;
        }
        return $major_val;
    }

    /** time - ON space ON 
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement2($nums) {
        $freq = [];
        $major = $nums[0];

        foreach($nums as $num) {
            if (array_key_exists($num, $freq)){
                $freq[$num]++;
            }
            else {
                $freq[$num] = 1;
            }
            $major = $freq[$num] > $freq[$major] ? $num : $major;
        } 
        return $major;
    }
}

?>