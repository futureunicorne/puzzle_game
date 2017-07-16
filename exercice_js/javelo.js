function compare (a, b) {
	if (a.foo < b.foo)
		return - 1;
	if (a.foo > b.foo)
		return 1;
	return (0);
}

function sortByFoo(tab) {
 	tab.sort(compare);
  return tab;
}

// Sort by .foo attribute
console.log(sortByFoo(
  [{foo: 5}, {foo: 7}, {foo: 4}, {foo: 3}, {foo: 2}, {foo: 1}, {foo: 6}]
)[5].foo === 6);

// Does not crash on an empty array
console.log(sortByFoo([]).length === 0);

// For objects without a `foo` attribute, its value should be considered equal to 0;
console.log(sortByFoo([{foo: 42}, {bar: 7}, {foo: -5}])[1].bar === 7);
