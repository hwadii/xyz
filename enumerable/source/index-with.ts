export function indexWith<T extends string | number | symbol>(
  list: T[],
  index: unknown
): Record<T, unknown> {
  return list
    .map((elem) => [elem, index] as const)
    .reduce((acc, curr) => {
      const [elem, index] = curr;
      acc[elem] = index;
      return acc;
    }, {} as Record<T, unknown>);
}
