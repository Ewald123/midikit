# MIDIList #
A list of MIDI objects of a common type.
```

struct MIDIList;
```
I realize that this a general purpose linked list and should not be restricted to MIDIKit use as the MIDI-prefix might indicate. I will evaluate and extract general purpose code at a later point.




---

## Creation and destruction ##
Creating, destroying and reference counting of MIDIConnector objects.


---


### `struct MIDIList * MIDIListCreate` ###
Create a [MIDIList](struct_m_i_d_i_list.md) instance.
```
struct MIDIList * MIDIListCreate(struct MIDITypeSpec *type);
```

Allocate space and initialize a [MIDIList](struct_m_i_d_i_list.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| type     | The type of the elements to be stored.  |

#### Return ####
a pointer to the created list structure on success. a `NULL` pointer if the list could not created.


---


### `void MIDIListDestroy` ###
Destroy a [MIDIList](struct_m_i_d_i_list.md) instance.
```
void MIDIListDestroy(struct MIDIList *list);
```

Free all resources occupied by the list and release all list items.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |



---


### `void MIDIListRetain` ###
Retain a [MIDIList](struct_m_i_d_i_list.md) instance.
```
void MIDIListRetain(struct MIDIList *list);
```

Increment the reference counter of a list so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |



---


### `void MIDIListRelease` ###
Release a [MIDIList](struct_m_i_d_i_list.md) instance.
```
void MIDIListRelease(struct MIDIList *list);
```

Decrement the reference counter of a list. If the reference count reached zero, destroy the list.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |



---

## List management ##
Functions for working with lists.


---


### `int MIDIListAdd` ###
Add an item to the list.
```
int MIDIListAdd(struct MIDIList *list, void *item);
```

Add one item to the list and retain it.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |
| item     | The item to add.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | otherwise.      |



---


### `int MIDIListRemove` ###
Remove an item from the list.
```
int MIDIListRemove(struct MIDIList *list, void *item);
```

Remove one item from the list and release it.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |
| item     | The item to remove.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | otherwise.      |



---


### `int MIDIListContains` ###
Check if an item is contained inside the list.
```
int MIDIListContains(struct MIDIList *list, void *item);
```

Step through all items and check if any item has the given address.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |
| item     | The item to search for.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | if the item is present in the list.  |
| -1        | if the item is not present in the list.  |
| >0        | if an error occurred.  |



---


### `int MIDIListFind` ###
Find a given item using a comparator function.
```
int MIDIListFind(struct MIDIList *list, void **item, void *info, int(*func)(void *, void *));
```

Step through all items and check if the given comparator returns 0.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |
| item     | The result-item.  |
| info     | The pointer to pass as the first parameter.  |
| func     | The comparator function.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | if the item is present in the list.  |
| -1        | if the item is not present in the list.  |
| >0        | if an error occurred.  |



---


### `int MIDIListApply` ###
Apply a function to all items in the list.
```
int MIDIListApply(struct MIDIList *list, void *info, int(*func)(void *, void *));
```

Call the given function once for every item in the list. Use the given `info` pointer as the first parameter when calling the function and the item as the second parameter.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| list     | The list.       |
| info     | The pointer to pass as the first parameter.  |
| func     | The function to apply.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | otherwise.      |