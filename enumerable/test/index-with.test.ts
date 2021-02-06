import { indexWith } from "../source/index-with";
import test from "ava";

test("creates an object with array elements as key and index as value", (t) => {
  const result = indexWith(["hello", "world"], 2);
  t.deepEqual(result, { hello: 2, world: 2 });
});

test("creates an empty object with empty array", (t) => {
  const result = indexWith([], 2);
  t.deepEqual(result, {});
});
