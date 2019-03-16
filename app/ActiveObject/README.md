# About ActiveObject
  - Models can inherit from `ActiveObject` for `AttributedObject` (which also inherits from `ActiveObject`).
  - When a model inherits from `ActiveObject`, it must implement:
    - `toCommaSeparated`
    - `getTableName`
  - When a model inherits from `AttributedObject`, it must implement:
    - All of the abstract members of `ActiveObject`, plus,
    - `getAttributeTableName` (the name of the table into which to store attribute values).
    - `getAttributeIdColumnName` (the name of the column in the above table into which to store the `id` of `this`)
  - Whether a model inherits from `ActiveObject` or `AttributedObject`, it gains access to the following:
    - `.create()` (instance, saves the record to the database and sets the `id` of the instance to that of the record that was just created)
    - `.save()` (instance, updates the record to the database if it exists, otherwise automatically runs `create`)
    - `.destroy()` (instance, deletes the record in the database, but does not delete the instance)
    - `::all()` (static, returns a vector containing all the records of the model's type)
    - `::first()` (static, returns the first record of type)
    - `::last()` (static, returns the last record of type)
    - `::count()` (static, returns the number of records of type)
    - `::where(id)` (static, returns a record where `id` matches)
    - `::where(colName, value)` (static, returns a record where a column's value matches)
  - In `AttributedObject`, you also get access to these:
    - `.setAttr(attrName, int)` (sets an attribute, or updates if it does not exist, given an attribute name and its target value)
    - _Dangerous:_ `.setAttr(attrId, int)` (sets an attribute, or updates if it does not exist, given an attribute `id` and its target value)
    - `.attr(attrName)` (gets the value of the attribute for this object given an attribute name)
    - _Dangerous:_ `.attr(attrId)` (gets the value of the attribute for this object given an attribute `id`)
    - `.clearAttr(attrName)` (deletes the attribute for this object given an attribute name)
    - _Dangerous:_ `.clearAttr(attrId)` (deletes the attribute for this object given an attribute `id`)

**Note:**
When accessing `->first()` on a vector retrieved using `::where()` or `::all()`, for example, make sure to check:
```cpp
if (<vector>.isEmpty()) {
  <handle empty>
}
```
to avoid an QVector assert error!

Also, check for `nullptr` when using `::first()` or `::last()`, for example.  `nullptr` is returned if a query returns no results.

You will also need to `delete` or `free` the pointers that are returned by the `ActiveObject` methods.
