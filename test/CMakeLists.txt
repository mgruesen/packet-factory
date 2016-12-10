add_subdirectory(packet)
add_subdirectory(field)
add_subdirectory(field_store)

add_test(packet packet/test-packet)
add_test(field field/test-field)
add_test(field_store field_store/test-field_store)
