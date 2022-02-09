package main

func replaceSpace(s string) string {
	bytes := []byte(s)
	oldSize := len(bytes)
	cnt := 0
	for _, v := range bytes {
		if v == ' ' {
			cnt++
		}
	}

	tmp := make([]byte, 2*cnt)
	bytes = append(bytes, tmp...)
	newSize := len(bytes)

	i := oldSize - 1
	j := newSize - 1
	for i >= 0 {
		if bytes[i] != ' ' {
			bytes[j] = bytes[i]
			i--
			j--
		} else {
			bytes[j] = '0'
			bytes[j-1] = '2'
			bytes[j-2] = '%'
			i--
			j -= 3
		}
	}
	return string(bytes)
}
