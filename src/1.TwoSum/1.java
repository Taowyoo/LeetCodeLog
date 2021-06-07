/*
 * File: 1.java
 * File Created: 2021-01-04 20:48:36 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/two-sum/
 * -----
 * Last Modified: 2021-01-04 21:03:14 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

/**
 * Two pass solution
 */
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i) {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}


/**
 * One pass solution
 */
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}