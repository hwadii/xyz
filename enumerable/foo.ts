import { indexBy } from "./source/index-by";

interface Thing {
  id: number;
  bar: string | string[];
}

const things: Thing[] = [
  { id: 1, bar: ["thing", "foo"] },
  { id: 2, bar: "other thing" },
];
const indexed = indexBy(things, "id");
console.log(indexed);
