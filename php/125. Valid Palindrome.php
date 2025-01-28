<?php

class Solution {

    function isPalindrome($s) {
        $s = preg_replace('/[^a-z0-9]/', '', strtolower($s));
        return $s === strrev($s);
    }

    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome2($s) {
        $left = 0;
        $right = strlen($s)-1;

        while ($left < $right) {
            while($left < $right && !ctype_alnum($s[$left])) {
                $left++;
            }
            while($left < $right && !ctype_alnum($s[$right])) {
                $right--;
            }
            if ($left < $right && strtolower($s[$left]) !== strtolower($s[$right])) {
                return false; 
            }
            $left++;
            $right--;
        }
        
        return true;
    }
}

?>