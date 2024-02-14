#!/usr/bin/node

/**
 * @param {number[]} nums
 * @return {number[]}
 */
function rearrangeArray (nums) {
  if (!nums | nums.length <= 1) { return nums; }

  const p = [];
  const n = [];
  const out = [];
  let i = 0;

  while (nums[i]) {
    if (nums[i] >= 0) {
      p.push(nums[i]);
    } else { n.push(nums[i]); }
    i++;
  }

  for (i = 0; i < p.length; i++) {
    out.push(p[i]);
    out.push(n[i]);
  }

  return out;
}

const nums = [3, 1, -2, -5, 2, -4];

rearrangeArray(nums);
rearrangeArray([-1, 1]);
