<?php

class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
       $data = [')'=>'(', '}'=>'{', ']'=>'['];
       $stack = [];

        for ($i = 0; $i < strlen($s); $i++) {
            $c = $s[$i];
            if (array_key_exists($c, $data)){
                if (empty($stack) || array_pop($stack) !== $data[$c]) {
                    return false; 
                }
            }
            else {
                array_push($stack, $c);
            }
       }
       return empty($stack); 
    }
}


?>