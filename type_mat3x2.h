static void
tmat3x2_dealloc(tmat3x2* self)
{
	Py_DECREF(self->x);
	Py_DECREF(self->y);
	Py_DECREF(self->z);
	//Py_DECREF(self->col_type);
	//Py_DECREF(self->row_type);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tmat3x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tmat3x2 *self;

	self = (tmat3x2 *)type->tp_alloc(type, 0);

	PyObject *v1 = pack_tvec2(0, 0);
	PyObject *v2 = pack_tvec2(0, 0);
	PyObject *v3 = pack_tvec2(0, 0);

	if (self != NULL) {
		self->x = (tvec2*)v1;
		self->y = (tvec2*)v2;
		self->z = (tvec2*)v3;
		self->col_type = (PyObject*)&tvec2Type;
		self->row_type = (PyObject*)&tvec3Type;
	}

	return (PyObject *)self;
}

static int
tmat3x2_init(tmat3x2 *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x0", "x1", "y0", "y1", "z0", "z1", NULL };

	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOOOOO", kwlist,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (IS_NUMERIC(arg1)) {
			self->x->x = self->y->y = pyvalue_as_double(arg1);
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_imat(arg1, &o);
		switch (vecType) {
		case GLM_TMAT2x2:
			self->x->x = ((imat2x2*)o)->x.x;
			self->x->y = ((imat2x2*)o)->x.y;
			self->y->x = ((imat2x2*)o)->y.x;
			self->y->y = ((imat2x2*)o)->y.y;
			self->z->x = 0.0;
			self->z->y = 0.0;
			free(o);
			return 0;
		case GLM_TMAT2x3:
			self->x->x = ((imat2x3*)o)->x.x;
			self->x->y = ((imat2x3*)o)->x.y;
			self->y->x = ((imat2x3*)o)->y.x;
			self->y->y = ((imat2x3*)o)->y.y;
			self->z->x = 0.0;
			self->z->y = 0.0;
			free(o);
			return 0;
		case GLM_TMAT2x4:
			self->x->x = ((imat2x4*)o)->x.x;
			self->x->y = ((imat2x4*)o)->x.y;
			self->y->x = ((imat2x4*)o)->y.x;
			self->y->y = ((imat2x4*)o)->y.y;
			self->z->x = 0.0;
			self->z->y = 0.0;
			free(o);
			return 0;
		case GLM_TMAT3x2:
			self->x->x = ((imat3x2*)o)->x.x;
			self->x->y = ((imat3x2*)o)->x.y;
			self->y->x = ((imat3x2*)o)->y.x;
			self->y->y = ((imat3x2*)o)->y.y;
			self->z->x = ((imat3x2*)o)->z.x;
			self->z->y = ((imat3x2*)o)->z.y;
			free(o);
			return 0;
		case GLM_TMAT3x3:
			self->x->x = ((imat3x3*)o)->x.x;
			self->x->y = ((imat3x3*)o)->x.y;
			self->y->x = ((imat3x3*)o)->y.x;
			self->y->y = ((imat3x3*)o)->y.y;
			self->z->x = ((imat3x3*)o)->z.x;
			self->z->y = ((imat3x3*)o)->z.y;
			free(o);
			return 0;
		case GLM_TMAT3x4:
			self->x->x = ((imat3x4*)o)->x.x;
			self->x->y = ((imat3x4*)o)->x.y;
			self->y->x = ((imat3x4*)o)->y.x;
			self->y->y = ((imat3x4*)o)->y.y;
			self->z->x = ((imat3x4*)o)->z.x;
			self->z->y = ((imat3x4*)o)->z.y;
			free(o);
			return 0;
		case GLM_TMAT4x2:
			self->x->x = ((imat4x2*)o)->x.x;
			self->x->y = ((imat4x2*)o)->x.y;
			self->y->x = ((imat4x2*)o)->y.x;
			self->y->y = ((imat4x2*)o)->y.y;
			self->z->x = ((imat4x2*)o)->z.x;
			self->z->y = ((imat4x2*)o)->z.y;
			free(o);
			return 0;
		case GLM_TMAT4x3:
			self->x->x = ((imat4x3*)o)->x.x;
			self->x->y = ((imat4x3*)o)->x.y;
			self->y->x = ((imat4x3*)o)->y.x;
			self->y->y = ((imat4x3*)o)->y.y;
			self->z->x = ((imat4x3*)o)->z.x;
			self->z->y = ((imat4x3*)o)->z.y;
			free(o);
			return 0;
		case GLM_TMAT4x4:
			self->x->x = ((imat4x4*)o)->x.x;
			self->x->y = ((imat4x4*)o)->x.y;
			self->y->x = ((imat4x4*)o)->y.x;
			self->y->y = ((imat4x4*)o)->y.y;
			self->z->x = ((imat4x4*)o)->z.x;
			self->z->y = ((imat4x4*)o)->z.y;
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
			return -1;
		}
	}
	if (arg3 == NULL) {
		return 0;
	}

	if (arg4 == NULL) {
		ivec2* o = unpack_ivec2(arg1);
		if (o == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
			return -1;
		}
		ivec2* o2 = unpack_ivec2(arg2);
		if (o2 == NULL) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
			return -1;
		}
		ivec2* o3 = unpack_ivec2(arg3);
		if (o3 == NULL) {
			free(o);
			free(o2);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
			return -1;
		}
		self->x->x = o->x;
		self->x->y = o->y;
		self->y->x = o2->x;
		self->y->y = o2->y;
		self->z->x = o3->x;
		self->z->y = o3->y;
		free(o);
		free(o2);
		free(o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
		return -1;
	}

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		self->x->x = pyvalue_as_double(arg1);
		self->x->y = pyvalue_as_double(arg2);
		self->y->x = pyvalue_as_double(arg3);
		self->y->y = pyvalue_as_double(arg4);
		self->z->x = pyvalue_as_double(arg5);
		self->z->y = pyvalue_as_double(arg6);
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x2()");
	return -1;
}

// unaryfunc
static PyObject *
tmat3x2_neg(tmat3x2 *obj)
{
	PyObject* argList = Py_BuildValue("OOO", PyObject_CallMethod((PyObject*)obj->x, "__neg__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__neg__", "()"), PyObject_CallMethod((PyObject*)obj->z, "__neg__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat3x2_pos(tmat3x2 *obj)
{
	PyObject* argList = Py_BuildValue("OOO", obj->x, obj->y, obj->z);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat3x2_abs(tmat3x2 *obj)
{
	PyObject* argList = Py_BuildValue("OOO", PyObject_CallMethod((PyObject*)obj->x, "__abs__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__abs__", "()"), PyObject_CallMethod((PyObject*)obj->z, "__abs__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

// binaryfunc
static PyObject *
tmat3x2_add(PyObject *obj1, PyObject *obj2)
{
	imat3x2 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.y.x = o.y.y = o.z.x = o.z.y = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat3x2
		if (!unpack_imat3x2p(obj1, &o)) { // obj1 can't be interpreted as tmat3x2
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::tmat3x2'");
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x += d;
		o.x.y += d;
		o.y.x += d;
		o.y.y += d;
		o.z.x += d;
		o.z.y += d;
	}
	else { // obj2 can be converted to a tmat3x2
		imat3x2 o2;

		if (!unpack_imat3x2p(obj2, &o2)) { // obj2 can't be interpreted as tmat3x2
			PyObject * out = PyObject_CallMethod(obj2, "__radd__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tmat3x2' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x += o2.x.x;
		o.x.y += o2.x.y;
		o.y.x += o2.y.x;
		o.y.y += o2.y.y;
		o.z.x += o2.z.x;
		o.z.y += o2.z.y;
	}

	return build_imat3x2(o);
}

static PyObject *
tmat3x2_sub(PyObject *obj1, PyObject *obj2)
{
	imat3x2 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.y.x = o.y.y = o.z.x = o.z.y = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat3x2
		if (!unpack_imat3x2p(obj1, &o)) { // obj1 can't be interpreted as tmat3x2
			PY_TYPEERROR_2O("unsupported operand type(s) for -: ", obj1, obj2);
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x -= d;
		o.x.y -= d;
		o.y.x -= d;
		o.y.y -= d;
		o.z.x -= d;
		o.z.y -= d;
	}
	else { // obj2 can be converted to a tmat3x2
		imat3x2 o2;

		if (!unpack_imat3x2p(obj2, &o2)) { // obj2 can't be interpreted as tmat3x2
			PyObject * out = PyObject_CallMethod(obj2, "__rsub__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tmat3x2' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x -= o2.x.x;
		o.x.y -= o2.x.y;
		o.y.x -= o2.y.x;
		o.y.y -= o2.y.y;
		o.z.x -= o2.z.x;
		o.z.y -= o2.z.y;
	}

	return build_imat3x2(o);
}

static PyObject *
tmat3x2_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat3x2* o2 = unpack_imat3x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat3x2
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat3x2' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat3x2(
			d * o2->x.x,
			d * o2->x.y,
			d * o2->y.x,
			d * o2->y.y,
			d * o2->z.x,
			d * o2->z.y);
		free(o2);
		return out;
	}

	void* o = NULL;
	char glmType = unpack_pyobject(obj1, &o, GLM_HAS_TVEC2 | GLM_HAS_TMAT3x2);

	if (glmType == GLM_TVEC2) { // obj1 is a col_type
		imat3x2* o2 = unpack_imat3x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat3x2
			free(o);
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat3x2' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tvec3(
			((ivec2*)o)->x * o2->x.x + ((ivec2*)o)->y * o2->x.y,
			((ivec2*)o)->x * o2->y.x + ((ivec2*)o)->y * o2->y.y,
			((ivec2*)o)->x * o2->z.x + ((ivec2*)o)->y * o2->z.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType != GLM_TMAT3x2) { // obj1 can't be interpreted as tmat3x2
		free(o);
		PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat3x2*)o)->x.x *= d;
		((imat3x2*)o)->x.y *= d;
		((imat3x2*)o)->y.x *= d;
		((imat3x2*)o)->y.y *= d;
		((imat3x2*)o)->z.x *= d;
		((imat3x2*)o)->z.y *= d;
		PyObject* out = build_imat3x2p(o);
		free(o);
		return out;
	}

	void* o2 = NULL;
	glmType = unpack_pyobject(obj2, &o2, GLM_HAS_TVEC3 | GLM_HAS_TMAT2x3 | GLM_HAS_TMAT3x3 | GLM_HAS_TMAT4x3);

	if (glmType == GLM_TVEC3) { // obj2 is a row_type
		PyObject* out = pack_tvec2(
			((imat3x2*)o)->x.x * ((ivec3*)o2)->x + ((imat3x2*)o)->y.x * ((ivec3*)o2)->y + ((imat3x2*)o)->z.x * ((ivec3*)o2)->z,
			((imat3x2*)o)->x.y * ((ivec3*)o2)->x + ((imat3x2*)o)->y.y * ((ivec3*)o2)->y + ((imat3x2*)o)->z.y * ((ivec3*)o2)->z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT2x3) { // obj2 is a tmat2x3
		PyObject* out = pack_tmat2x2(
			((imat3x2*)o)->x.x * ((imat2x3*)o2)->x.x + ((imat3x2*)o)->y.x * ((imat2x3*)o2)->x.y + ((imat3x2*)o)->z.x * ((imat2x3*)o2)->x.z,
			((imat3x2*)o)->x.y * ((imat2x3*)o2)->x.x + ((imat3x2*)o)->y.y * ((imat2x3*)o2)->x.y + ((imat3x2*)o)->z.y * ((imat2x3*)o2)->x.z,
			((imat3x2*)o)->x.x * ((imat2x3*)o2)->y.x + ((imat3x2*)o)->y.x * ((imat2x3*)o2)->y.y + ((imat3x2*)o)->z.x * ((imat2x3*)o2)->y.z,
			((imat3x2*)o)->x.y * ((imat2x3*)o2)->y.x + ((imat3x2*)o)->y.y * ((imat2x3*)o2)->y.y + ((imat3x2*)o)->z.y * ((imat2x3*)o2)->y.z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT3x3) {// obj2 is a tmat3x3
		PyObject* out = pack_tmat3x2(
			((imat3x2*)o)->x.x * ((imat3x3*)o2)->x.x + ((imat3x2*)o)->y.x * ((imat3x3*)o2)->x.y + ((imat3x2*)o)->z.x * ((imat3x3*)o2)->x.z,
			((imat3x2*)o)->x.y * ((imat3x3*)o2)->x.x + ((imat3x2*)o)->y.y * ((imat3x3*)o2)->x.y + ((imat3x2*)o)->z.y * ((imat3x3*)o2)->x.z,
			((imat3x2*)o)->x.x * ((imat3x3*)o2)->y.x + ((imat3x2*)o)->y.x * ((imat3x3*)o2)->y.y + ((imat3x2*)o)->z.x * ((imat3x3*)o2)->y.z,
			((imat3x2*)o)->x.y * ((imat3x3*)o2)->y.x + ((imat3x2*)o)->y.y * ((imat3x3*)o2)->y.y + ((imat3x2*)o)->z.y * ((imat3x3*)o2)->y.z,
			((imat3x2*)o)->x.x * ((imat3x3*)o2)->z.x + ((imat3x2*)o)->y.x * ((imat3x3*)o2)->z.y + ((imat3x2*)o)->z.x * ((imat3x3*)o2)->z.z,
			((imat3x2*)o)->x.y * ((imat3x3*)o2)->z.x + ((imat3x2*)o)->y.y * ((imat3x3*)o2)->z.y + ((imat3x2*)o)->z.y * ((imat3x3*)o2)->z.z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT4x3) { // obj2 is a tmat4x3
		PyObject* out = pack_tmat4x2(
			((imat3x2*)o)->x.x * ((imat4x3*)o2)->x.x + ((imat3x2*)o)->y.x * ((imat4x3*)o2)->x.y + ((imat3x2*)o)->z.x * ((imat4x3*)o2)->x.z,
			((imat3x2*)o)->x.y * ((imat4x3*)o2)->x.x + ((imat3x2*)o)->y.y * ((imat4x3*)o2)->x.y + ((imat3x2*)o)->z.y * ((imat4x3*)o2)->x.z,
			((imat3x2*)o)->x.x * ((imat4x3*)o2)->y.x + ((imat3x2*)o)->y.x * ((imat4x3*)o2)->y.y + ((imat3x2*)o)->z.x * ((imat4x3*)o2)->y.z,
			((imat3x2*)o)->x.y * ((imat4x3*)o2)->y.x + ((imat3x2*)o)->y.y * ((imat4x3*)o2)->y.y + ((imat3x2*)o)->z.y * ((imat4x3*)o2)->y.z,
			((imat3x2*)o)->x.x * ((imat4x3*)o2)->z.x + ((imat3x2*)o)->y.x * ((imat4x3*)o2)->z.y + ((imat3x2*)o)->z.x * ((imat4x3*)o2)->z.z,
			((imat3x2*)o)->x.y * ((imat4x3*)o2)->z.x + ((imat3x2*)o)->y.y * ((imat4x3*)o2)->z.y + ((imat3x2*)o)->z.y * ((imat4x3*)o2)->z.z,
			((imat3x2*)o)->x.x * ((imat4x3*)o2)->w.x + ((imat3x2*)o)->y.x * ((imat4x3*)o2)->w.y + ((imat3x2*)o)->z.x * ((imat4x3*)o2)->w.z,
			((imat3x2*)o)->x.y * ((imat4x3*)o2)->w.x + ((imat3x2*)o)->y.y * ((imat4x3*)o2)->w.y + ((imat3x2*)o)->z.y * ((imat4x3*)o2)->w.z);
		free(o);
		free(o2);
		return out;
	}
	free(o);
	free(o2);
	PyObject * out = PyObject_CallMethod(obj2, "__rmul__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat3x2' and ", obj2);
		return NULL;
	}
	return out;
}

static PyObject *
tmat3x2_div(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat3x2* o2 = unpack_imat3x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat3x2
			PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat3x2' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat3x2(
			d / o2->x.x,
			d / o2->x.y,
			d / o2->y.x,
			d / o2->y.y,
			d / o2->z.x,
			d / o2->z.y);
		free(o2);
		return out;
	}

	imat3x2* o = unpack_imat3x2(obj1);

	if (o == NULL) { // obj1 can't be interpreted as tmat3x2
		PY_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat3x2*)o)->x.x /= d;
		((imat3x2*)o)->x.y /= d;
		((imat3x2*)o)->y.x /= d;
		((imat3x2*)o)->y.y /= d;
		((imat3x2*)o)->z.x /= d;
		((imat3x2*)o)->z.y /= d;
		PyObject* out = build_imat3x2p(o);
		free(o);
		return out;
	}
	free(o);
	PyObject * out = PyObject_CallMethod(obj2, "__rtruediv__", "O", obj1);
	if (out == NULL) out = PyObject_CallMethod(obj2, "__rdiv__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat3x2' and ", obj2);
		return NULL;
	}
	return out;
}

// inplace
// binaryfunc
static PyObject *
tmat3x2_iadd(tmat3x2 *self, PyObject *obj)
{
	tmat3x2 * temp = (tmat3x2*)tmat3x2_add((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x2_isub(tmat3x2 *self, PyObject *obj)
{
	tmat3x2 * temp = (tmat3x2*)tmat3x2_sub((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x2_imul(tmat3x2 *self, PyObject *obj)
{
	tmat3x2 * temp = (tmat3x2*)tmat3x2_mul((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	if (!PyObject_TypeCheck(temp, &tmat3x2Type)) {
		PY_TYPEERROR("unsupported operand type for *=: ", obj);
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x2_idiv(tmat3x2 *self, PyObject *obj)
{
	tmat3x2 * temp = (tmat3x2*)tmat3x2_div((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	if (!PyObject_TypeCheck(temp, &tmat3x2Type)) {
		PY_TYPEERROR("unsupported operand type for /=: ", obj);
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x2_str(tmat3x2* self)
{
	char * out = (char*)malloc((106) * sizeof(char));
	snprintf(out, 106, "tmat3x2( ( %12.6g, %12.6g ), ( %12.6g, %12.6g ), ( %12.6g, %12.6g ) )", self->x->x, self->x->y, self->y->x, self->y->y, self->z->x, self->z->y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
tmat3x2_repr(tmat3x2* self)
{
	char * out = (char*)malloc((104) * sizeof(char));
	snprintf(out, 104, "tmat3x2\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->x->x, self->x->y, self->y->x, self->y->y, self->z->x, self->z->y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tmat3x2_len(tmat3x2 * self) {
	return (Py_ssize_t)3;
}

static PyObject* tmat3x2_sq_item(tmat3x2 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		Py_INCREF((PyObject*)self->x);
		return (PyObject*)self->x;
	case 1:
		Py_INCREF((PyObject*)self->y);
		return (PyObject*)self->y;
	case 2:
		Py_INCREF((PyObject*)self->z);
		return (PyObject*)self->z;
	case -1:
		Py_INCREF((PyObject*)self->z);
		return (PyObject*)self->z;
	case -2:
		Py_INCREF((PyObject*)self->y);
		return (PyObject*)self->y;
	case -3:
		Py_INCREF((PyObject*)self->x);
		return (PyObject*)self->x;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int tmat3x2_sq_setitem(tmat3x2 * self, Py_ssize_t index, PyObject * value) {
	ivec2*o = unpack_ivec2(value);
	if (o == NULL) {
		PY_TYPEERROR("expected tvec2, got ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->x->x = o->x;
		self->x->y = o->y;
		free(o);
		return 0;
	case 1:
		self->y->x = o->x;
		self->y->y = o->y;
		free(o);
		return 0;
	case 2:
		self->z->x = o->x;
		self->z->y = o->y;
		free(o);
		return 0;
	case -1:
		self->z->x = o->x;
		self->z->y = o->y;
		free(o);
		return 0;
	case -2:
		self->y->x = o->x;
		self->y->y = o->y;
		free(o);
		return 0;
	case -3:
		self->x->x = o->x;
		self->x->y = o->y;
		free(o);
		return 0;
	default:
		free(o);
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tmat3x2_contains(tmat3x2 * self, PyObject * value) {
	if (IS_NUMERIC(value)) {
		double d = pyvalue_as_double(value);
		return (int)(d == self->x->x || d == self->x->y || d == self->y->x || d == self->y->y || d == self->z->x || d == self->z->y);
	}
	ivec2* o = unpack_ivec2(value);
	if (o == NULL) {
		return 0;
	}

	int out = (int)((self->x->x == o->x && self->x->y == o->y) || (self->y->x == o->x && self->y->y == o->y) || (self->z->x == o->x && self->z->y == o->y));
	free(o);
	return out;
}

static PyObject * tmat3x2_richcompare(tmat3x2 * self, PyObject * other, int comp_type) {
	tmat3x2 * other_as_tmat3x2;
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tmat3x2Type)) { // incopatible type
			Py_RETURN_FALSE;
		}
		else {
			other_as_tmat3x2 = (tmat3x2*)other;
		}
		return PyBool_FromLong(
			(self->x->x == other_as_tmat3x2->x->x) && (self->x->y == other_as_tmat3x2->x->y) &&
			(self->y->x == other_as_tmat3x2->y->x) && (self->y->y == other_as_tmat3x2->y->y) &&
			(self->z->x == other_as_tmat3x2->z->x) && (self->z->y == other_as_tmat3x2->z->y));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tmat3x2Type)) { // incopatible type
			Py_RETURN_TRUE;
		}
		else {
			other_as_tmat3x2 = (tmat3x2*)other;
		}
		return PyBool_FromLong(
			(self->x->x != other_as_tmat3x2->x->x) || (self->x->y != other_as_tmat3x2->x->y) ||
			(self->y->x != other_as_tmat3x2->y->x) || (self->y->y != other_as_tmat3x2->y->y) ||
			(self->z->x != other_as_tmat3x2->z->x) || (self->z->y != other_as_tmat3x2->z->y));
	}
	else {
		PY_TYPEERROR("unsupported operand type(s) for ==: 'glm::detail::tmat3x2 and ", other);
		return NULL;
	}
}

static int tmat3x2_setattr(PyObject * obj, PyObject * name, PyObject * value) {
	char * name_as_ccp;
#if PY3K
	name_as_ccp = PyBytes_AsString(PyUnicode_AsASCIIString(name));
#else
	name_as_ccp = PyString_AsString(PyUnicode_AsASCIIString(name));
#endif
	if ((strlen(name_as_ccp) >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[strlen(name_as_ccp) - 1] == '_' && name_as_ccp[strlen(name_as_ccp) - 2] == '_')) {
		return PyObject_GenericSetAttr(obj, name, value);
	}
	if (strcmp(name_as_ccp, "x") == 0) {
		ivec2* o = unpack_ivec2(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat3x2*)obj)->x->x = o->x;
		((tmat3x2*)obj)->x->y = o->y;
		free(o);
		return 0;
	}
	if (strcmp(name_as_ccp, "y") == 0) {
		ivec2* o = unpack_ivec2(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat3x2*)obj)->y->x = o->x;
		((tmat3x2*)obj)->y->y = o->y;
		free(o);
		return 0;
	}
	if (strcmp(name_as_ccp, "z") == 0) {
		ivec2* o = unpack_ivec2(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat3x2*)obj)->z->x = o->x;
		((tmat3x2*)obj)->z->y = o->y;
		free(o);
		return 0;
	}
	return PyObject_GenericSetAttr(obj, name, value);
}

// iterator

static PyObject *
tmat3x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tmat3x2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tmat3x2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tmat3x2Iter *rgstate = (tmat3x2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tmat3x2Iter_dealloc(tmat3x2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tmat3x2Iter_next(tmat3x2Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index) {
		case 0:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->x));
			return (PyObject*)(rgstate->sequence->x);
		case 1:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->y));
			return (PyObject*)(rgstate->sequence->y);
		case 2:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->z));
			return (PyObject*)(rgstate->sequence->z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * tmat3x2_geniter(tmat3x2 * self) {
	PyObject * obj = tmat3x2Iter_new(&tmat3x2IterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tmat3x2SeqMethods = {
	(lenfunc)tmat3x2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tmat3x2_sq_item, // sq_item
	0,
	(ssizeobjargproc)tmat3x2_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tmat3x2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMemberDef tmat3x2_members[] = {
	{ "x", T_OBJECT, offsetof(tmat3x2, x), 0,
	"vec x" },
{ "y", T_OBJECT, offsetof(tmat3x2, y), 0,
"vec y" },
{ "z", T_OBJECT, offsetof(tmat3x2, z), 0,
"vec z" },
{ "col_type", T_OBJECT, offsetof(tmat3x2, col_type), 0,
"column type" },
{ "row_type", T_OBJECT, offsetof(tmat3x2, row_type), 0,
"row type" },
{ NULL }  /* Sentinel */
};

#if PY3K
static PyNumberMethods tmat3x2NumMethods = {
	(binaryfunc)tmat3x2_add,
	(binaryfunc)tmat3x2_sub,
	(binaryfunc)tmat3x2_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)tmat3x2_neg, //nb_negative
	(unaryfunc)tmat3x2_pos, //nb_positive
	(unaryfunc)tmat3x2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)tmat3x2_iadd, //nb_inplace_add
	(binaryfunc)tmat3x2_isub, //nb_inplace_subtract
	(binaryfunc)tmat3x2_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)tmat3x2_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)tmat3x2_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tmat3x2NumMethods = {
	(binaryfunc)tmat3x2_add, //nb_add;
	(binaryfunc)tmat3x2_sub, //nb_subtract;
	(binaryfunc)tmat3x2_mul, //nb_multiply;
	(binaryfunc)tmat3x2_div, //nb_divide;
	0, //nb_remainder;
	0, //nb_divmod;
	0, //nb_power;
	(unaryfunc)tmat3x2_neg, //nb_negative;
	(unaryfunc)tmat3x2_pos, //nb_positive;
	(unaryfunc)tmat3x2_abs, //nb_absolute;
	0, //nb_nonzero;       /* Used by PyObject_IsTrue */
	0, //nb_invert;
	0, //nb_lshift;
	0, //nb_rshift;
	0, //nb_and;
	0, //nb_xor;
	0, //nb_or;
	0, //nb_coerce;       /* Used by the coerce() function */
	0, //nb_int;
	0, //nb_long;
	0, //nb_float;
	0, //nb_oct;
	0, //nb_hex;

	   /* Added in release 2.0 */
	   (binaryfunc)tmat3x2_iadd, //nb_inplace_add;
	   (binaryfunc)tmat3x2_isub, //nb_inplace_subtract;
	   (binaryfunc)tmat3x2_imul, //nb_inplace_multiply;
	   (binaryfunc)tmat3x2_idiv, //nb_inplace_divide;
	   0, //nb_inplace_remainder;
	   0, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  0, //nb_floor_divide;
		  (binaryfunc)tmat3x2_div, //nb_true_divide;
		  0, //nb_inplace_floor_divide;
		  (binaryfunc)tmat3x2_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tmat3x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tmat3x2",             /* tp_name */
	sizeof(tmat3x2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat3x2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tmat3x2_repr,                         /* tp_repr */
	&tmat3x2NumMethods,             /* tp_as_number */
	&tmat3x2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tmat3x2_str,                         /* tp_str */
	0,//(getattrofunc)tmat3x2_getattr,                         /* tp_getattro */
	(setattrofunc)tmat3x2_setattr,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"tmat3x2( <tmat3x2 compatible type(s)> )\n3 columns of 2 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tmat3x2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tmat3x2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tmat3x2_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tmat3x2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tmat3x2_new,                 /* tp_new */
};

static PyTypeObject tmat3x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tmat3x2Iter",             /* tp_name */
	sizeof(tmat3x2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat3x2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"tmat3x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tmat3x2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tmat3x2Iter_new,                 /* tp_new */
};