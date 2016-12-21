# -*- coding: utf-8 -*-

from flask import Blueprint, request
from flask_login import login_user, logout_user
from app.models import User

api = Blueprint(
        'api',
        __name__
        )

@api.route('/login')
def login():
    username = request.args.get('username')
    password = request.args.get('password')
    user = User.query.filter_by(username=username).first()
    if user is not None and user.verify_password(password):
        return '1'
    return '0'
