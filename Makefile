.PHONY: clean All

All:
	@echo "----------Building project:[ Final-Project-Group2 - Debug ]----------"
	@cd "Final-Project-Group2" && "$(MAKE)" -f  "Final-Project-Group2.mk"
clean:
	@echo "----------Cleaning project:[ Final-Project-Group2 - Debug ]----------"
	@cd "Final-Project-Group2" && "$(MAKE)" -f  "Final-Project-Group2.mk" clean
