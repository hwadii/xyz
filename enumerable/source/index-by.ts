import { ConditionalKeys, DefaultRecord } from "..";

export function indexBy<
  T,
  K extends ConditionalKeys<T, string | number | symbol>
>(list: T[], index: K): DefaultRecord<T> {
  return list
    .map((elem) => [elem[index], elem])
    .reduce((acc: any, curr) => {
      const [index, elem] = curr;
      acc[index] = elem;
      return acc;
    }, {});
}
