#pragma once
#include <tuple>


template <class K, class V>
struct element {
	K key;
	V value;
	int index;

};



template<class K, class V>
class Map {
	element<K, V>* m;
	int count;
	int size;

public:
	Map() {
		size = 1;
		count = 0;
		m = new element<K, V>[size];
	}

	void Set(K key, V value) {

		if (count == 0)
		{
			element<K, V> c;
			c.index = 0;
			c.key = key;
			c.value = value;
			m[0] = c;
			count++;
		}
		else
		{
			int i;
			bool ok;
			ok = false;
			for (i = 0; i < count; i++)
				if (m[i].key == key) {
					m[i].value = value;
					ok = true;
				}
			if (!ok)
			{
				if (count == size)
				{
					element<K, V>* c1 = new element<K, V>[size];
					for (int i = 0; i < size; ++i)
						c1[i] = (std::move(m[i]));
					delete[]m;
					size *= 2;
					m = new element<K, V>[size];
					for (int i = 0; i < count; ++i)
					{
						m[i] = (std::move(c1[i]));
					}
					delete[]c1;
				}
				element<K, V> c;
				c.index = count;
				c.key = key;
				c.value = value;
				m[count] = c;
				count++;
			}
		}

	}

	bool Get(const K& key, V& value) {

		for (int i = 0; i < count; i++) {
			if (m[i].key == key) {
				value =m[i].value;
				return true;
			}
		}
		return false;

	}

	int Count() { return count; }

	void Clear() {
		delete[] m;
		size = 1;
		count = 0;
		m = new element<K, V>[size];
	}

	bool Delete(const K& key) {
		for (int i = 0; i < count; i++) {
			if (m[i].key == key) {
				for (int j = i + 1; j < count; j++) {
					m[j].index--;
					m[j - 1] = m[j];
				}
				count--;
				return true;
			}
		}
		return false;
	}


	V& operator[](K Key) {
		if (!count) {
			element<K, V>c;
			c.key = Key;
			c.index = 0;
			m[0] = c;
			count++;
			return m[0].value;
		}

		else {
			for (auto i = 0; i < count; i++) {
				if (m[i].key == Key) return m[i].value;
			}
			if (count == size) {
				element<K, V>* c1 = new element<K, V>[size];
				for (auto i = 0; i < count; i++) {
					c1[i] = m[i];
				}
				delete[] m;
				size *= 2;
				m = new element<K, V>[size];
				for (auto i = 0; i < count; i++) {
					m[i] = c1[i];
				}
				delete[] c1;
			}
			element<K, V> c;
			c.index = count;
			c.key = Key;
			m[count] = c;
			count++;
			return m[count - 1].value;
		}
	}



	element<K, V>* begin() { return &m[0]; }

	element<K, V>* end() { return &m[count]; }

	bool Includes(const Map<K, V>& map) {
		for (int i = 0; i < map.count; i++)
		{
			bool ok = 0;
			for (int j = 0; j < count; j++) {
				if (map[i].key == m[i].key) {
					ok = 1;
				}
			}
			if (ok == 0) return false;
		}
		return true;
	}


};