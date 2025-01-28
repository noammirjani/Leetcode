<?php
class Solution {

    /**
     * @param String $paragraph
     * @param String[] $banned
     * @return String
     */

     // time - Omax(m,n) space On+m
    function mostCommonWord($paragraph, $banned) {
        $freq = [];
        $common = "";
        // W+ - matches any non-word character
        $paragraph = preg_split('/\W+/', strtolower($paragraph));
        
        foreach($banned as $word) $freq[$word] = -1;

        foreach($paragraph as $word) {
            if (!array_key_exists($word, $freq )) $freq[$word]= 1;
            else if ($freq[$word] != -1) $freq[$word]++;

            if (empty($common) || $freq[$word] > $freq[$common])
                $common = $word;
        }
        return $common;
    }
}
?>