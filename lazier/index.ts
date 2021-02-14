function* takeWhile<T extends unknown>(
  list: T[],
  condition: (arg: T) => boolean
): Generator<T> {
  for (const elem of list) {
    if (condition(elem)) {
      yield elem;
    }
  }
}

function* defineSeries(
  u0: number,
  max: number,
  series: (n: number) => number
): Generator<number> {
  let value = u0;
  let currentIteration = 0;
  yield value; // yield U₀
  while (currentIteration < max) {
    value = series(value);
    yield value; // yield Uₙ
    currentIteration++;
  }
}

function collect<T extends unknown>(generator: Generator<T>): T[] {
  return Array.from(generator);
}

const things: number[] = Array(100)
  .fill(0)
  .map((_, i) => i);

const taken = takeWhile(things, (thing) => thing % 2 === 0);
// const nums = collect(taken);

const series = defineSeries(1, 5, (n) => 2 * n + 1);
// const seried = collect(series);
console.log(series.next());
console.log(series.next());
console.log(series.next());
console.log(series.next());
console.log(series.next());
console.log(series.next());
