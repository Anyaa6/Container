

		/*
		//DOES NOT WORK WITH GEEKSFORGEEKS CODE EITHER
		bool hasRedChild(_node *x) 
		{
			return ((x->left != NULL && x->left->color == RED) || (x->right != NULL && x->right->color == RED));
		};
		
		void fixDoubleBlack(_node *x, _node *parent) {
			std::cout << "FIXDOUBLEBLACK" << std::endl;
			if (x == _root)
				return;
	
			_node *sibling = _get_sibling(x, parent);
			
			if (sibling == NULL) 
				fixDoubleBlack(parent, parent->parent);
			else //has sibling
			{
				if (sibling->color == RED) //sibling RED
				{
					sibling->color = BLACK;
					parent->color = RED;
					if (_is_on_left(sibling))
						_right_rotate(parent);
					else 
						_left_rotate(parent);
					fixDoubleBlack(x, parent);
				} 
				else //sibling black
				{
					if (hasRedChild(sibling)) 
					{
						if (sibling->left != NULL && sibling->left->color == RED) 
						{
							if (_is_on_left(sibling)) 
							{
								// left left
								sibling->left->color = sibling->color;
								sibling->color = parent->color;
								_right_rotate(parent);
							} 
							else 
							{
								// right left
								sibling->left->color = parent->color;
								_right_rotate(sibling);
								_left_rotate(parent);
							}
						} 
						else 
						{
							if (_is_on_left(sibling))
							{
								// left right
								sibling->right->color = parent->color;
								_left_rotate(sibling);
								_right_rotate(parent);
							} 
							else 
							{
								// right right
								sibling->right->color = sibling->color;
								sibling->color = parent->color;
								_left_rotate(parent);
							}
						}
						parent->color = BLACK;
					} 
					else //2 black children
					{
						sibling->color = RED;
						if (parent->color == BLACK)
							fixDoubleBlack(parent, parent->parent);
						else
							parent->color = BLACK;
					}
				}
			}
		}
		*/

			// NEW balance_erase()
		//if deleted and replacing are black THEN only we need rebalance
		//(if replacing is red it becomes black)

		//What if S does not exist ?? THen CANNOT HAVE CHILDS --> Then should recurse on parent
		//
		
		//case 1 S is BLACK and both childs black (-> sibling and current give a black to parent)
		// sibling becomes RED (and current loses doble black)
		//if parent is red then becomes black
		//if parent is black then becomes double black == recurse

		//case 2 S is BLACK and INNER CHILD RED
		//switch color of INNER CHILD (becomes BLACK) and S (becomes RED)
		//Rotation to the OUTSIDE on S (if S is right child - right rotate | if left child - left rotate)
		//recurse on current

		//case 3 S is BLACK and OUTER CHILD IS RED
		//OUTER CHILD becomes BLACK
		//Parent and Sibling exchange colors
		//Rotation on parent Toward current (if S is right child, left rotate | if S if left child, right rotate)
		//FINAL CASE

		//case 4 S is RED
		//exchange color of P and S
		//Rotate parent toward current (if S is right child, left rotate | if S if left child, right rotate)
		//recurse on C ??




		void erase (iterator position) {
			std::cout << "\n========================================================" << std::endl;
			std::cout << "Erasing = " << position->first << std::endl;
			
			_node *to_delete = _convert_iterator_to_node(_root, position);
			_node *replacing_node = NULL;
			_node *to_delete_parent = to_delete->parent;//changed here
			bool to_delete_color = to_delete->color;
			bool deleting_root = false;
			
			if (to_delete == _end)
				return;

			if (to_delete == _root) {
				deleting_root = true;
				// std::cout << "deleting ROOT - DOWN" << std::endl;
			}
				
			if (to_delete->right && to_delete->left) {
				to_delete_parent = _get_predecessor(to_delete)->parent;
				replacing_node = _erase_node_2_childs(to_delete);
			}
			else {
				if (to_delete == _begin)
					((_begin->right) ? (_begin = _begin->right) : (_begin = _begin->parent));
				replacing_node = _remove_node_from_tree(to_delete);
				_delete_node(to_delete);
			}
			
			if (deleting_root) {
				_root = replacing_node;
				if (replacing_node)
					replacing_node->parent = _root;
			}
			
			//if replacing_node is red then will be changed to black and exit
			//so only case where rebalancing happens is if delete and replacing are black
			// if (replacing_node)
			std::cout << "replacing node = " << (replacing_node ? (replacing_node->val_ptr->first) : (0)) << std::endl;
			// if (to_delete_parent)
				// std::cout << "to_delete_parent node = " << to_delete_parent->val_ptr->first << std::endl;
			//check when deleting the only node existing
			print_tree();

			//A CHANGER ??
			if (to_delete_color == BLACK) {
				if (replacing_node && replacing_node->color == RED) {
					std::cout << "Replacing Node is RED - becomes black and exit" << std::endl;
					replacing_node->color = BLACK;
				}
				else {
					std::cout << "Balancing - to_delete is black AND replace is BLACK" << std::endl;
					//!! TO DELETE PARENT IS NOT OK
					_balance_erase(replacing_node, to_delete_parent);
					// _balance_erase(replacing_node, to_delete_parent);
					// (void)to_delete_parent;
					//BEWARE IF REPLACING NODE HAS LEFT CHILD
				}
			}
		};