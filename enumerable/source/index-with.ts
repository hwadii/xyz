export function indexWith<
  T extends string | number | symbol,
  U extends unknown
>(list: T[], index: U): Record<T, U> {
  return list
    .map((elem) => [elem, index] as const)
    .reduce((acc, curr) => {
      const [elem, index] = curr;
      acc[elem] = index;
      return acc;
    }, {} as Record<T, U>);
}
